package yy.tongqu;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.NameValuePair;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.protocol.HTTP;
import org.apache.http.util.EntityUtils;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class LoginActivity extends Activity {

    private static final int MSG_SUCCESS = 0;
    private static final int MSG_FAILURE = 1;
    private static final int MSG_LOGINFAIL = 2;

    private Button button;
    private Thread mThread;
    private EditText editText1, editText2;
    private String username, password;
    //private boolean running = false;
    public LoginActivity() {
        // TODO Auto-generated constructor stub
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.login);

        button = (Button)this.findViewById(R.id.button1);
        editText1 = (EditText)this.findViewById(R.id.editText1);
        editText2 = (EditText)this.findViewById(R.id.editText2);
        button.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View arg0) {
                // TODO Auto-generated method stub
                if (mThread == null) {
                    mThread = new Thread(runnable);
                    //running = true;
                    mThread.start();

                    // 否则提示："线程已经启动"
                } else {
                    Toast toast=Toast.makeText(getApplicationContext(), "线程已启动", Toast.LENGTH_SHORT);
                    toast.show();
                }
                //String username = editText1.getText().toString();
////				String password = editText2.getText().toString();
//				Intent intent = new Intent();
//				intent.putExtra("username", username);
//				intent.putExtra("password", password);
//				
//				setResult(RESULT_OK, intent);
//				finish();
            }
        });


    }

    private Handler mHandler = new Handler() {
        // 重写handleMessage()方法，此方法在UI线程运行
        @Override
        public void handleMessage(Message msg) {
            switch (msg.what) {
                // 如果成功，则显示从网络获取到的图片
                case MSG_SUCCESS:
                    Toast toast=Toast.makeText(getApplicationContext(), "登录成功", Toast.LENGTH_SHORT);
                    toast.show();
                    Intent intent = new Intent();
                    intent.putExtra("session", (String)msg.obj);
                    intent.putExtra("login", (String)"OK");
                    setResult(RESULT_OK, intent);
                    //running = false;
                    mThread.interrupt();
                    mThread = null;
                    finish();
                    break;
                // 否则提示失败
                case MSG_FAILURE:
                    Toast toast1=Toast.makeText(getApplicationContext(), "出错了", Toast.LENGTH_SHORT);
                    toast1.show();
                    //running = false;
                    mThread.interrupt();
                    mThread = null;
                    break;
                case MSG_LOGINFAIL:
                    Toast toast2=Toast.makeText(getApplicationContext(), "登录失败", Toast.LENGTH_SHORT);
                    toast2.show();
                    //running = false;
                    mThread.interrupt();
                    mThread = null;
                    break;
            }
        }
    };

    Runnable runnable = new Runnable() {
        // 重写run()方法，此方法在新的线程中运行
        @Override
        public void run() {

            String uriAPI = "http://tongqu.me/index.php/api/user/login"; //这是我测试的本地,大家可以随意改
            username = editText1.getText().toString();
            password = editText2.getText().toString();

            //String result = null;
            //HttpResponse response = null;
        /*建立HTTPost对象*/
            HttpPost httpRequest = new HttpPost(uriAPI);
        /* 
         * NameValuePair实现请求参数的封装 
        */
            List <NameValuePair> params = new ArrayList <NameValuePair>();
            params.add(new BasicNameValuePair("user_name", username));
            params.add(new BasicNameValuePair("password", password));
            try
            {
          /* 添加请求参数到请求对象*/
                httpRequest.setEntity(new UrlEncodedFormEntity(params, HTTP.UTF_8));
          /*发送请求并等待响应*/
                HttpResponse httpResponse = new DefaultHttpClient().execute(httpRequest);
          /*若状态码为200 ok*/
                if(httpResponse.getStatusLine().getStatusCode() == 200)
                {
            /*读返回数据*/
                    String strResult = httpResponse.getFirstHeader("Set-Cookie").getValue();
                    String raw = EntityUtils.toString(httpResponse.getEntity());
                    String str = null;
                    Pattern p=Pattern.compile("ci_session_id=(.*?); expires");
                    Matcher m=p.matcher(strResult);
                    while(m.find()){
                        str = m.group(1);
                    }
                    if (raw.charAt(raw.indexOf("error")+7) == '1') {
                        mHandler.obtainMessage(MSG_LOGINFAIL, "登录失败").sendToTarget();
                    } else {
                        mHandler.obtainMessage(MSG_SUCCESS, str).sendToTarget();
                    }
                }
                else
                {
                    mHandler.obtainMessage(MSG_FAILURE).sendToTarget();
                }
            }
            catch (ClientProtocolException e)
            {
                mHandler.obtainMessage(MSG_FAILURE).sendToTarget();
                e.printStackTrace();
            }
            catch (IOException e)
            {
                mHandler.obtainMessage(MSG_FAILURE).sendToTarget();
                e.printStackTrace();
            }
            catch (Exception e)
            {
                mHandler.obtainMessage(MSG_FAILURE).sendToTarget();
                e.printStackTrace();
            }
        }
    };

}
