package me.yiminghe.rnplayground;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.KeyEvent;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    public final static String BUNDLE_URL = "me.yiminghe.rnplayground.MESSAGE";
    private static final int OVERLAY_PERMISSION_REQUEST_CODE = 2;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final MainActivity self = this;
        final EditText editText = (EditText) findViewById(R.id.bundleUrl);
        editText.setOnEditorActionListener(new TextView.OnEditorActionListener() {
            @Override
            public boolean onEditorAction(TextView textView, int keyCode, KeyEvent keyEvent) {
                if (keyEvent.getAction() == KeyEvent.ACTION_DOWN &&
                        keyEvent.getKeyCode() == KeyEvent.KEYCODE_ENTER) {
                    return true;
                }
                if (keyEvent.getAction() == KeyEvent.ACTION_UP &&
                        keyEvent.getKeyCode() == KeyEvent.KEYCODE_ENTER) {
                    Intent intent = new Intent(self, MyReactActivity.class);
                    intent.putExtra(BUNDLE_URL, textView.getText().toString());
                    startActivityForResult(intent, OVERLAY_PERMISSION_REQUEST_CODE);
                    return true;
                }
                return false;
            }
        });
    }
}
