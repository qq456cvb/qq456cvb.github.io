package yy.tongqu;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import org.apache.http.HttpResponse;
import org.apache.http.NameValuePair;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.protocol.HTTP;
import org.apache.http.util.EntityUtils;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;


public class MainActivity extends Activity {

    private static final int MSG_SUCCESS = 0;
    private static final int MSG_FAILURE = 1;

    private Button start, post;
    //private TextView mTextView1, mTextView2;
    private Thread mThread;
    private String sessionId;
    private String login = null;
    private EditText title, phone, content;
    AlertDialog.Builder dlgBuilder;




    public String convert(String utfString){
        StringBuilder sb = new StringBuilder();
        int i = -1;
        int pos = 0;

        while((i=utfString.indexOf("\\u", pos)) != -1){
            sb.append(utfString.substring(pos, i));
            if(i+5 < utfString.length()){
                pos = i+6;
                sb.append((char)Integer.parseInt(utfString.substring(i+2, i+6), 16));
            }
        }

        sb.append(utfString.substring(pos));
        return sb.toString();
    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

//		mTextView1 = (TextView) this.findViewById(R.id.textView1);
//		mTextView2 = (TextView) this.findViewById(R.id.textView2);




        start = (Button) this.findViewById(R.id.button1);
        start.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View arg0) {
                // TODO Auto-generated method stub
                Intent intent = new Intent(MainActivity.this, LoginActivity.class);
                startActivityForResult(intent, 1000);
            }
        });

        post = (Button) this.findViewById(R.id.button2);
        post.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View arg0) {
                if (login == null) {
                    Toast toast = Toast.makeText(getApplicationContext(), "请先登录", Toast.LENGTH_SHORT);
                    toast.show();
                    return;
                }
                LayoutInflater layoutInflater = LayoutInflater.from(MainActivity.this);
                final View reportView = layoutInflater.inflate(R.layout.report, null);
                dlgBuilder = new AlertDialog.Builder(MainActivity.this);
//				if (mThread == null) {
//                    mThread = new Thread(runnable);
//                    mThread.start();
//
//                    // 否则提示："线程已经启动"
//                } else {
//                	mTextView1.setText("线程已启动！");
//                }
                dlgBuilder.setTitle("用户反馈").
                        setIcon(R.drawable.ic_launcher).
                        setView(reportView).
                        setNegativeButton("提交", new DialogInterface.OnClickListener() {

                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                // TODO Auto-generated method stub
                                title = (EditText) reportView.findViewById(R.id.editText1);
                                phone = (EditText) reportView.findViewById(R.id.editText2);
                                content = (EditText) reportView.findViewById(R.id.editText3);
                                if (mThread == null) {
                                    mThread = new Thread(runnable);
                                    mThread.start();

                                    // 否则提示："线程已经启动"
                                } else {
                                    new AlertDialog.Builder(MainActivity.this)
                                            .setTitle("警告")
                                            .setMessage("线程已启动!")
                                            .setPositiveButton("确定", null)
                                            .show();
                                }
                            }
                        }).
                        setPositiveButton("取消", new DialogInterface.OnClickListener() {

                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                // TODO Auto-generated method stub
                                dialog.dismiss();
                            }
                        });
                Dialog alertDialog = dlgBuilder.create();

                alertDialog.show();
                // TODO Auto-generated method stub


            }
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == 1000 && resultCode == RESULT_OK)
        {
            sessionId = data.getStringExtra("session");
            login = data.getStringExtra("login");
            //mTextView2.setText(sessionId);
        }
    };

    private Handler mHandler = new Handler() {
        // 重写handleMessage()方法，此方法在UI线程运行
        @Override
        public void handleMessage(Message msg) {
            switch (msg.what) {
                // 如果成功，则显示从网络获取到的图片
                case MSG_SUCCESS:
                    //mTextView1.setText(convert((String)msg.obj));
                    String msgrecv = (String)msg.obj;
                    msgrecv = msgrecv.substring(msgrecv.indexOf("msg") + 6, msgrecv.length() - 2);
                    new AlertDialog.Builder(MainActivity.this)
                            .setTitle("接受数据")
                            .setMessage(convert(msgrecv))
                            .setPositiveButton("确定", null)
                            .show();
                    new AlertDialog.Builder(MainActivity.this)
                            .setTitle("发送数据")
                            .setMessage("向服务器发送数据: \n title=" + title.getText().toString()
                                    + "&phone=" + phone.getText().toString()
                                    + "&content=" + content.getText().toString())
                            .setPositiveButton("确定", null)
                            .show();

                    mThread.interrupt();
                    mThread = null;
                    break;
                // 否则提示失败
                case MSG_FAILURE:
                    new AlertDialog.Builder(MainActivity.this)
                            .setTitle("警告")
                            .setMessage("出错了!")
                            .setPositiveButton("确定", null)
                            .show();
                    //mTextView1.setText("出错了！");
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
            String uriAPI = "http://www.tongqu.me/index.php/api/bug"; //这是我测试的本地,大家可以随意改
        /*建立HTTPost对象*/
            HttpPost httpRequest = new HttpPost(uriAPI);
            httpRequest.addHeader("Cookie", "ci_session_id=" + sessionId);
        /*
         * NameValuePair实现请求参数的封装
        */
            List<NameValuePair> params = new ArrayList<NameValuePair>();
            params.add(new BasicNameValuePair("title", title.getText().toString()));
            params.add(new BasicNameValuePair("phone", phone.getText().toString()));
            params.add(new BasicNameValuePair("content", content.getText().toString()));
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
                    String strResult = EntityUtils.toString(httpResponse.getEntity());
                    mHandler.obtainMessage(MSG_SUCCESS, strResult).sendToTarget();
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
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}
