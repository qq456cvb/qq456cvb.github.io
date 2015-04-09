	


function Timer() {
  this.start_ = new Date();

  this.elapsed = function() {
    return (new Date()) - this.start_;
  }

  this.reset = function() {
    this.start_ = new Date();
  }
}
	// An object used for caching data about the browser's cookies, which we update
	// as notifications come in.
function CookieCache() {
  this.cookies_ = {};

  this.reset = function() {
    this.cookies_ = {};
  }

  this.add = function(cookie) {
    //alert(JSON.stringify(cookie.domain));
    var domain = cookie.domain;
    if (!this.cookies_[domain]) {
      this.cookies_[domain] = [];
    }
    this.cookies_[domain].push(cookie);
  };

  this.remove = function(cookie) {
    var domain = cookie.domain;
    if (this.cookies_[domain]) {
      var i = 0;
      while (i < this.cookies_[domain].length) {
        if (cookieMatch(this.cookies_[domain][i], cookie)) {
          this.cookies_[domain].splice(i, 1);
        } else {
          i++;
        }
      }
      if (this.cookies_[domain].length == 0) {
        delete this.cookies_[domain];
      }
    }
  };

  // Returns a sorted list of cookie domains that match |filter|. If |filter| is
  //  null, returns all domains.
  this.getDomains = function(filter) {
    var result = [];
    sortedKeys(this.cookies_).forEach(function(domain) {
      if (!filter || domain.indexOf(filter) != -1) {
        result.push(domain);
      }
    });
    return result;
  }

  this.getCookies = function(domain) {
    return this.cookies_[domain];
  };
}
	

var cache = new CookieCache();
var xmlHttpRequest;   
var timer = new Timer();  
var status = -1; // no get  
var arr = new Array();
var check_arr = new Array();
var type = 0;
  
var storage = window.localStorage;

if (storage.length == 0) {
  alert("首次启动！");
} else {
  for (var i=0, len = storage.length; i < len; i++){
    var key = storage.key(i);
    var value = storage.getItem(key);
    console.log(key + " = " + value);
    arr = value.split(","); 
    type = 1;
    setInterval(myCheck, 5000);
  }
}



//XmlHttpRequest对象    
function createXmlHttpRequest(){    
	//alert("yes!");
    if(window.ActiveXObject){ //如果是IE浏览器    
        return new ActiveXObject("Microsoft.XMLHTTP");    
    }else if(window.XMLHttpRequest){ //非IE浏览器    
        return new XMLHttpRequest();    
    }    
}    
    
function onLogin(){     

    var url = "http://electsys.sjtu.edu.cn/edu/index.aspx";       
            
    //1.创建XMLHttpRequest组建    
    xmlHttpRequest = createXmlHttpRequest();    
        
    //2.设置回调函数    
    xmlHttpRequest.onreadystatechange = yyFun;    
        
    //3.初始化XMLHttpRequest组建    
    xmlHttpRequest.open("POST",url,false);   

    //请求头 
    xmlHttpRequest.setRequestHeader("Accept", "application/x-ms-application, image/jpeg, application/xaml+xml, image/gif, image/pjpeg, application/x-ms-xbap, */*");
    xmlHttpRequest.setRequestHeader("Accept-Language", "zh-CN");
    xmlHttpRequest.setRequestHeader("Pragma", "no-cache");
    xmlHttpRequest.setRequestHeader("Content-Type","application/x-www-form-urlencoded");  
     
    //4.发送请求    
    var data = "txtUserName=5120379104&txtPwd=08193012&rbtnLst=1&Button1=%E7%99%BB%E5%BD%95";
    xmlHttpRequest.send(data);      
}  

function onGet(){      
    

    var url = "http://jwc.jxnu.edu.cn/";       
            
    //1.创建XMLHttpRequest组建    
    xmlHttpRequest = createXmlHttpRequest();    
        
    //2.设置回调函数    
    xmlHttpRequest.onreadystatechange = yyFun;    
        
    //3.初始化XMLHttpRequest组建    
    xmlHttpRequest.open("GET",url,true);   

    //请求头 
    xmlHttpRequest.setRequestHeader("Accept", "application/x-ms-application, image/jpeg, application/xaml+xml, image/gif, image/pjpeg, application/x-ms-xbap, */*");
    xmlHttpRequest.setRequestHeader("Accept-Language", "zh-CN");
    //xmlHttpRequest.setRequestHeader("Pragma", "no-cache");
    xmlHttpRequest.setRequestHeader("Content-Type","application/x-www-form-urlencoded");  
     

    //status = 1;
    xmlHttpRequest.send(null);      
} 

function onPost(){    

    var url = "http://electsys.sjtu.edu.cn/edu/StudentScore/B_StudentScoreQuery.aspx";       
            
    //1.创建XMLHttpRequest组建    
    xmlHttpRequest = createXmlHttpRequest();    
        
    //2.设置回调函数    
    xmlHttpRequest.onreadystatechange = yyFun;    
        
    //3.初始化XMLHttpRequest组建    
    xmlHttpRequest.open("POST",url,false);   

    //请求头 
    xmlHttpRequest.setRequestHeader("Accept", "application/x-ms-application, image/jpeg, application/xaml+xml, image/gif, image/pjpeg, application/x-ms-xbap, */*");
    xmlHttpRequest.setRequestHeader("Accept-Language", "zh-CN");
    xmlHttpRequest.setRequestHeader("Pragma", "no-cache");
    xmlHttpRequest.setRequestHeader("Content-Type","application/x-www-form-urlencoded");  
     
    //4.发送请求    
    var data = "__VIEWSTATE=%2FwEPDwUKLTk3NTM2NzEyOA8WAh4JcG9zdFRpbWVzAgEWAgIBD2QWDAIBDw8WAh4EVGV4dAUG5bCk5rSLZGQCAw8PFgIfAQUKNTEyMDM3OTEwNGRkAgUPDxYCHwEFCEYxMjAzNzA0ZGQCBw8QDxYCHgtfIURhdGFCb3VuZGdkEBUQCSAgICAgICAgIAkyMDAwLTIwMDEJMjAwMS0yMDAyCTIwMDItMjAwMwkyMDAzLTIwMDQJMjAwNC0yMDA1CTIwMDUtMjAwNgkyMDA2LTIwMDcJMjAwNy0yMDA4CTIwMDgtMjAwOQkyMDA5LTIwMTAJMjAxMC0yMDExCTIwMTEtMjAxMgkyMDEyLTIwMTMJMjAxMy0yMDE0CTIwMTQtMjAxNRUQCSAgICAgICAgIAkyMDAwLTIwMDEJMjAwMS0yMDAyCTIwMDItMjAwMwkyMDAzLTIwMDQJMjAwNC0yMDA1CTIwMDUtMjAwNgkyMDA2LTIwMDcJMjAwNy0yMDA4CTIwMDgtMjAwOQkyMDA5LTIwMTAJMjAxMC0yMDExCTIwMTEtMjAxMgkyMDEyLTIwMTMJMjAxMy0yMDE0CTIwMTQtMjAxNRQrAxBnZ2dnZ2dnZ2dnZ2dnZ2dnZGQCCQ8QDxYCHwJnZBAVBAEgATEBMgEzFQQBIAExATIBMxQrAwRnZ2dnZGQCEw88KwALAGRkjDavT1zxkwa7mw6O6ot3T9ZRVE0%3D&__VIEWSTATEGENERATOR=C9518D52&__EVENTVALIDATION=%2FwEWGAKuxOsFArTI99wCAv3pxfwIAvzp8eoFAv%2Fp7fwLAvbpmekEAvnptfMKAvjpoekHAvvp3fMFAvLpyekGAvXppZAGAvrpzasIAqCrysUOAqOrjoQIAqKrksQJAr2r1oQLAryrusQIAt%2Bvw%2BoJAtCvw%2BoJAtGvw%2BoJAtKvw%2BoJAt6n0MYFAqWf8%2B4KAq%2BauagMkzjKfNxiJ1Xt%2BvTyQlENhe2DBS8%3D&ddlXN=2014-2015&ddlXQ=1&txtKCDM=&btnSearch=++%E6%9F%A5++%E8%AF%A2++";
    xmlHttpRequest.send(data);      
}       
    
    
//回调函数    
function yyFun(){  
	
	//alert(xmlHttpRequest.readyState);
    if(xmlHttpRequest.readyState == 4 && xmlHttpRequest.status == 200){    
        var b = xmlHttpRequest.responseText; 
        // if (status == 1) {
        // 	status = 0;
          
       // alert(b); 
	        var pos1 = b.indexOf("<!--内容-->");
	        var pos2 = b.indexOf("<!--登录窗口-->");
	        sfind = b.substring(pos1, pos2);
          
          if (type == 1) {
            //alert("checking");
            var found = 0;
            check_arr = sfind.split("</div>");
            for ( var i=0 ; i < check_arr.length - 2; ++i )
            {
              var p1 = check_arr[i].indexOf("aspx>");
              var p2 = check_arr[i].indexOf("</a>");
              check_arr[i] = check_arr[i].substring(p1 + 5, p2);
              for ( var j=0 ; j < arr.length - 2; ++j ) 
              {
                if (check_arr[i] == arr[j]) {
                  found = 1;
                  break;
                };
              }
              if (found == 0) {
                var divide = new Array();
                divide = check_arr[i].split(" ");
                var notification = webkitNotifications.createNotification(
                  'test.png',  // icon url - can be relative
                  divide[0],  // notification title
                  divide[1]  // notification body text
                );
                notification.show();
              };
            }
          } else {
            arr = sfind.split("</div>");
            for ( var i=0 ; i < arr.length - 2; ++i ) 
            {
              var p1 = arr[i].indexOf("aspx>");
              var p2 = arr[i].indexOf("</a>");
              arr[i] = arr[i].substring(p1 + 5, p2);
              alert(arr[i]); 

              var divide = new Array();
              divide = arr[i].split(" ");

              var notification = webkitNotifications.createNotification(
                'test.png',  // icon url - can be relative
                divide[0],  // notification title
                divide[1]  // notification body text
              );
              notification.show();
             
            }
            type = 1;
            storage.setItem("arr", arr);
            setInterval(myCheck, 5000);
          };        
                 
    }    
} 

function getCookie(){
	chrome.cookies.get({"url": "http://electsys.sjtu.edu.cn/", 
    "name": "ASP.NET_SessionId"}, function(cookies) {
	if (cookies == null) {
		alert("no cookie!");
		onLogin();
	};
    for (var i in cookies) {
      alert(i + ":" + cookies[i]);
      cache.add(cookies[i]);
    }
  })
}



chrome.browserAction.onClicked.addListener(function() {
  	//onGet();
  chrome.tabs.create({url: "file:///C:/Users/Administrator/Desktop/mailqq.html"}, function(tab) {
    //setTimeout(delay, 2000);
  });
});

function myCheck() {
  onGet();
};

function delay() {
  chrome.tabs.executeScript(null, {file: "yy.js"}, function() {
    setTimeout(writePage, 2000);
  });
}

function writePage() {
  chrome.tabs.executeScript(null, {file: "yy2.js"}, function() {
  });
}

