//
//  ViewController.m
//  RNPlayground
//
//  Created by Denis Swain on 16/1/19.
//  Copyright © 2016年 MyBank. All rights reserved.
//

#import "HomeController.h"
#import "QRCodeReaderViewController.h"
#import "RCTRootView.h"

@interface HomeController () <UITextFieldDelegate, QRCodeReaderDelegate>
@property UIButton *scanButton;
@property UIActivityIndicatorView *loadIndicator;
@property QRCodeReaderViewController *vc;
@property UITextField *textField;
@end

@implementation HomeController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.title = @"react-native-0.28.0";
    
    UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, 280, 80)];
    label.textColor = [UIColor blackColor];
    label.tag = 91;
    label.backgroundColor = [UIColor whiteColor];
    label.text = @"input:";
    label.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:label];

    
    UIButton *scanButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [scanButton setBackgroundImage:[UIImage imageNamed:@"Scan"] forState:UIControlStateNormal];
    scanButton.frame = CGRectMake(0, 0, 256, 256);
    [scanButton setTitle:@"Scan" forState:UIControlStateNormal];
    [scanButton addTarget:self action:@selector(scanPressHandler:) forControlEvents:UIControlEventTouchUpInside];
    self.scanButton = scanButton;
    self.scanButton.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:self.scanButton];
    
    self.textField = [[UITextField alloc] init];
    self.textField.delegate = self;
    self.textField.borderStyle = UITextBorderStyleRoundedRect;
    self.textField.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:self.textField];
    
    self.loadIndicator = [[UIActivityIndicatorView alloc]initWithFrame:CGRectMake(0, 0, 100, 100)];
    self.loadIndicator.center = self.view.center;
    [self.loadIndicator setActivityIndicatorViewStyle:UIActivityIndicatorViewStyleWhiteLarge];//设置进度轮显示类型
    [self.view addSubview:self.loadIndicator];
    
    NSDictionary *nameMap = @{
                              @"label": label,
                              @"textField": self.textField,
                              @"scanButton": self.scanButton
                              };
    NSArray *horizontalConstraints =
    [NSLayoutConstraint constraintsWithVisualFormat:@"H:|-5-[label(45)]-[textField]-5-|"
                                            options:0
                                            metrics:nil
                                              views:nameMap];
    
    NSArray *verticalConstraints =
    [NSLayoutConstraint constraintsWithVisualFormat:@"V:|-100-[textField(30)]"
                                            options:0
                                            metrics:nil
                                              views:nameMap];
    
    NSArray *verticalConstraints2 =
    [NSLayoutConstraint constraintsWithVisualFormat:@"V:|-100-[label(30)]"
                                            options:0
                                            metrics:nil
                                              views:nameMap];
    
    [self.view addConstraints:horizontalConstraints];
    [self.view addConstraints:verticalConstraints];
    [self.view addConstraints:verticalConstraints2];
    [self.view addConstraint:[NSLayoutConstraint constraintWithItem:self.scanButton attribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:self.view attribute:NSLayoutAttributeCenterX multiplier:1 constant:0]];
    
    [self.view addConstraint:[NSLayoutConstraint constraintWithItem:self.scanButton attribute:NSLayoutAttributeCenterY relatedBy:NSLayoutRelationEqual toItem:self.view attribute:NSLayoutAttributeCenterY multiplier:1 constant:0]];
    
    // Create the reader object
    QRCodeReader *reader = [QRCodeReader readerWithMetadataObjectTypes:@[AVMetadataObjectTypeQRCode]];
    
    // Instantiate the view controller
    QRCodeReaderViewController *vc = [QRCodeReaderViewController readerWithCancelButtonTitle:@"Cancel" codeReader:reader startScanningAtLoad:YES showSwitchCameraButton:YES showTorchButton:YES];
    
    // Set the presentation style
    vc.modalPresentationStyle = UIModalPresentationFormSheet;
    
    // Define the delegate receiver
    vc.delegate = self;
    
    self.vc = vc;
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    // NSLog(@"%@", textField.text);
    [self openRNView:textField.text];
    return YES;
}

- (void)scanPressHandler:(id)sender {
    [self presentViewController:self.vc animated:YES completion:NULL];
    [self startLoading];
}

#pragma mark - QRCodeReader Delegate Methods
- (void)readerDidCancel:(QRCodeReaderViewController *)reader {
    [self dismissViewControllerAnimated:YES completion:NULL];
    [self stopLoading];
}

-(void)openRNView:(NSString *)result {
    @try {
        NSURL *url = [NSURL URLWithString:result];
        NSString *lastPathComponent = url.lastPathComponent;
        
        NSArray *components = [lastPathComponent componentsSeparatedByString:@"."];
        NSMutableString *moduleName = [[NSMutableString alloc] initWithString:components[0]];
        for(int i = 1; i < [components count]-1; i++) {
            NSString* part = [components objectAtIndex:i];
            [moduleName appendString:@"."];
            [moduleName appendString:part];
        }
        
        RCTRootView *rootView = [[RCTRootView alloc] initWithBundleURL:url
                                                            moduleName:moduleName
                                                     initialProperties:nil
                                                         launchOptions:nil];
        UIViewController *vc = [[UIViewController alloc] init];
        vc.edgesForExtendedLayout = UIRectEdgeNone;
        vc.view = rootView;
        vc.view.frame = [UIScreen mainScreen].bounds;
        vc.title = @"RN Demo";
        [self.navigationController pushViewController:vc animated:YES];
        [self stopLoading];
    }
    @catch (NSException *exception) {
        NSLog(@"Exception:%@", [exception reason]);
        [self stopLoading];
        UIAlertController* alert = [UIAlertController
                                    alertControllerWithTitle:nil
                                    message:@"该二维码不是一个有效的项目入口文件地址"
                                    preferredStyle:UIAlertControllerStyleAlert];
        
        UIAlertAction* defaultAction = [UIAlertAction actionWithTitle:@"确定"
                                                                style:UIAlertActionStyleDefault handler:nil];
        
        [alert addAction:defaultAction];
    }
    @finally {
        
    }
}

- (void)reader:(QRCodeReaderViewController *)reader didScanResult:(NSString *)result {
    [self dismissViewControllerAnimated:YES completion:^{
        NSLog(@"ScarnQR URL: %@", result);
        [self openRNView:result];
    }];
}

- (void)startLoading {
    self.scanButton.enabled = NO;
    [self.loadIndicator startAnimating];
}

- (void)stopLoading {
    self.scanButton.enabled = YES;
    [self.loadIndicator stopAnimating];    
}

@end
