function parseData (UIData,UpdateData) {
  for (n in UIData) {
    if(UIData[n][0]=="%") {
      UIData[n]=UpdateData[UIData[n][1]];
    }
  }
  return UIData;
}
function generate () {

}
function update () {

}
