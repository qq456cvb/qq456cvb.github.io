package com.example.tongqu;


import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import org.apache.http.HttpResponse;
import org.apache.http.NameValuePair;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.protocol.HTTP;
import org.apache.http.util.EntityUtils;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import android.os.Build;
import android.preference.PreferenceManager.OnActivityResultListener;

import com.example.tongqu.Login;

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
				Intent intent = new Intent(MainActivity.this, Login.class);
				startActivityForResult(intent, 1000);
			}
		});
		
		post = (Button) this.findViewById(R.id.button2);
		post.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				if (login == null) {
					Toast toast = Toast.makeText(getApplicationContext(), "���ȵ�¼", Toast.LENGTH_SHORT);
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
//                    // ������ʾ��"�߳��Ѿ�����"
//                } else {
//                	mTextView1.setText("�߳���������");
//                }
				dlgBuilder.setTitle("�û�����"). 
			            setIcon(R.drawable.ic_launcher). 
			            setView(reportView). 
			            setNegativeButton("�ύ", new DialogInterface.OnClickListener() { 
			
			                @Override 
			                public void onClick(DialogInterface dialog, int which) { 
			                    // TODO Auto-generated method stub  
			                	title = (EditText) reportView.findViewById(R.id.editText1);
			                	phone = (EditText) reportView.findViewById(R.id.editText2);
			                	content = (EditText) reportView.findViewById(R.id.editText3);
			                	if (mThread == null) {
			                      mThread = new Thread(runnable);
			                      mThread.start();
			   
			                      // ������ʾ��"�߳��Ѿ�����"
			                  } else {
			                	  new AlertDialog.Builder(MainActivity.this)  
					                .setTitle("����")
					                .setMessage("�߳�������!")
					                .setPositiveButton("ȷ��", null)
					                .show();
			                  }
			                } 
			            }). 
			            setPositiveButton("ȡ��", new DialogInterface.OnClickListener() { 
			
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
		// ��дhandleMessage()�������˷�����UI�߳�����
        @Override
        public void handleMessage(Message msg) {
            switch (msg.what) {
            // ����ɹ�������ʾ�������ȡ����ͼƬ
            case MSG_SUCCESS:
                //mTextView1.setText(convert((String)msg.obj));
            	String msgrecv = (String)msg.obj;
            	msgrecv = msgrecv.substring(msgrecv.indexOf("msg") + 6, msgrecv.length() - 2);
            	new AlertDialog.Builder(MainActivity.this)  
				                .setTitle("��������")
				                .setMessage(convert(msgrecv))
				                .setPositiveButton("ȷ��", null)
				                .show();
                new AlertDialog.Builder(MainActivity.this)  
                                .setTitle("��������")
                                .setMessage("���������������: \n title=" + title.getText().toString()
                                		+ "&phone=" + phone.getText().toString()
                                		+ "&content=" + content.getText().toString())
                                .setPositiveButton("ȷ��", null)
                                .show();
                
                mThread.interrupt();
            	mThread = null;
                break;
            // ������ʾʧ��
            case MSG_FAILURE:
            	new AlertDialog.Builder(MainActivity.this)  
				                .setTitle("����")
				                .setMessage("������!")
				                .setPositiveButton("ȷ��", null)
				                .show();
            	//mTextView1.setText("�����ˣ�");
            	mThread.interrupt();
            	mThread = null;
            	break;
            }
        }
    };
    
	Runnable runnable = new Runnable() {
    // ��дrun()�������˷������µ��߳�������
    @Override
    public void run() {
    	String uriAPI = "http://www.tongqu.me/index.php/api/bug"; //�����Ҳ��Եı���,��ҿ��������  
        /*����HTTPost����*/  
        HttpPost httpRequest = new HttpPost(uriAPI);  
        httpRequest.addHeader("Cookie", "ci_session_id=" + sessionId);
        /* 
         * NameValuePairʵ����������ķ�װ 
        */  
        List <NameValuePair> params = new ArrayList <NameValuePair>();  
        params.add(new BasicNameValuePair("title", title.getText().toString()));  
        params.add(new BasicNameValuePair("phone", phone.getText().toString()));  
        params.add(new BasicNameValuePair("content", content.getText().toString()));  
        try  
        {  
          /* �������������������*/  
          httpRequest.setEntity(new UrlEncodedFormEntity(params, HTTP.UTF_8));  
          /*�������󲢵ȴ���Ӧ*/  
          HttpResponse httpResponse = new DefaultHttpClient().execute(httpRequest);  
          /*��״̬��Ϊ200 ok*/  
          if(httpResponse.getStatusLine().getStatusCode() == 200)   
          {  
            /*����������*/  
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

	/**
	 * A placeholder fragment containing a simple view.
	 */

}
