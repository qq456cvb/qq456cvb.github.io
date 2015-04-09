

var mainframe = document.getElementById('mainFrame').contentWindow.document;

function callExe()  
{  
 
     // new ActiveXObject("Wscript.Shell").run("notepad.exe D:\\a.png.txt");
     //
  new ActiveXObject("Wscript.Shell").run("C:\\Users\\Administrator\\Desktop\\外挂.exe");
}

//callExe();
// mainframe.onkeydown=function(e){ 
//   var e = e|| event; 
//   if(e.keyCode==83){ 
//     e.preventDefault(); //阻止默认行为  
//     alert(String.fromCharCode(e.keyCode));
//   } 
// }

if (mainframe == null) {
  alert("error");
} else {
  alert(mainframe);
};

function getByClass(sDocument, sClass){
    var aResult=[];
    var aEle=sDocument.getElementsByTagName('*');
    for(var i=0;i<aEle.length;i++){
       /*当className相等时添加到数组中*/
       if(aEle[i].className==sClass){
            aResult.push(aEle[i]);
        }
    }
    return aResult;
};

var toAreaCtrl = mainframe.getElementById("toAreaCtrl"); 
var addr_text = getByClass(mainframe, "addr_text")[1];

var newdiv = mainframe.createElement("div");
newdiv.setAttribute("class", "addr_base addr_normal");
newdiv.setAttribute("style", "float:left;white-space:nowrap;");
newdiv.title = "447626601@qq.com";
newdiv.setAttribute("addr", "447626601@qq.com");
newdiv.setAttribute("unselectable", "on");
newdiv.innerHTML = "<b unselectable='on' addr='447626601@qq.com'>我自己的邮箱</b><span unselectable='on' addr='447626601@qq.com'>&lt;447626601<span class='domain' unselectable='on' addr='447626601@qq.com'>@qq.com</span>&gt;</span><span class='semicolon'>;</span><a href='javascript:;' class='addr_del' name='del'></a>";

toAreaCtrl.insertBefore(newdiv, addr_text);
// <div class="addr_base addr_normal" style="float:left;white-space:nowrap;" title="447626601@qq.com" addr="447626601@qq.com" unselectable="on">
// <b unselectable="on" 
// addr="447626601@qq.com">我自己的邮箱</b><span unselectable="on" 
// addr="447626601@qq.com">&lt;447626601<span class="domain" unselectable="on" 
// addr="447626601@qq.com">@qq.com</span>&gt;</span><span class="semicolon">;</span><a href="javascript:;" class="addr_del" name="del"></a></div>