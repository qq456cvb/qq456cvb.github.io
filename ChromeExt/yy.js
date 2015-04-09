

//alert(document.getElementById("composebtn"));

var card = document.getElementById("composebtn");

if(document.createEvent){  
  var ev = document.createEvent('HTMLEvents');  
  ev.initEvent('click', false, true);  
  card.dispatchEvent(ev);  
}  
else { 
  card.click();
}

