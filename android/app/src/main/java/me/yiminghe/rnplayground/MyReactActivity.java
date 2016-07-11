package me.yiminghe.rnplayground;

import android.content.Intent;
import android.util.Log;

import com.facebook.react.ReactActivity;
import com.facebook.react.ReactNativeHost;
import com.facebook.react.ReactPackage;
import com.facebook.react.shell.MainReactPackage;

import java.util.Arrays;
import java.util.List;

public class MyReactActivity extends ReactActivity {
    private ReactNativeHost mReactNativeHost;

    String getBundleUrl() {
        Intent intent = getIntent();
        String url = intent.getStringExtra(MainActivity.BUNDLE_URL);
        Log.v("getBundleUrl", url);
        return url;
    }

    protected boolean getUseDeveloperSupport() {
        return BuildConfig.DEBUG;
    }

    protected String getJSMainModuleName() {
        String bundleUrl = this.getBundleUrl();
        int lastSlash = bundleUrl.lastIndexOf("/");
        StringBuilder sb = new StringBuilder();
        for (int i = lastSlash + 1; i < bundleUrl.length(); i++) {
            if (bundleUrl.charAt(i) == '.') {
                break;
            } else {
                sb.append(bundleUrl.charAt(i));
            }
        }
        Log.v("getJSMainModuleName", sb.toString());
        return sb.toString();
    }

    /**
     * Returns the name of the main component registered from JavaScript.
     * This is used to schedule rendering of the component.
     */
    protected String getMainComponentName() {
        return this.getJSMainModuleName();
    }

    @Override
    public ReactNativeHost getReactNativeHost() {
        if (mReactNativeHost != null) {
            return mReactNativeHost;
        }

        mReactNativeHost = new ReactNativeHost(getApplication()) {
            @Override
            protected List<ReactPackage> getPackages() {
                return Arrays.<ReactPackage>asList(
                        new MainReactPackage()
                );
            }

            protected String getJSMainModuleName() {
                String bundleUrl = getBundleUrl();
                int pathIndex = bundleUrl.indexOf(":8081/") + ":8081/".length();
                int bundleIndex = bundleUrl.indexOf(".bundle");
                String jsModule =  bundleUrl.substring(pathIndex, bundleIndex);
                Log.v("getJSMainModuleName", jsModule);
                return jsModule;
            }

            /**
             * Returns whether dev mode should be enabled.
             * This enables e.g. the dev menu.
             */
            protected boolean getUseDeveloperSupport() {
                return BuildConfig.DEBUG;
            }

            protected String getJSBundleFile() {
                String bundleUrl = getBundleUrl();
                Log.v("getJSBundleFile", bundleUrl);
                return bundleUrl;
            }
        };
        return mReactNativeHost;
    }
}
