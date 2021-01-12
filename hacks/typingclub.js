function triggerKeyboardEvent(el, keyCode, type) {
  var eventObj = document.createEventObject
    ? document.createEventObject()
    : document.createEvent('Events');

  if (eventObj.initEvent) {
    eventObj.initEvent(type, true, true);
  }

  eventObj.keyCode = keyCode;
  eventObj.which = keyCode;

  el.dispatchEvent
    ? el.dispatchEvent(eventObj)
    : el.fireEvent('onkeydown', eventObj);
}

const content = document.querySelectorAll('.token_unit');
const text = [];

for (let i = 0; i < content.length; i++) {
  text[i] = content[i].childNodes[0].nodeValue;
}

console.log(text);
let i = 0;
function a() {
  if (i == content.length - 1) return;
  const input = $('html');
  triggerKeyboardEvent(input, text[i++], 'keydown');
  triggerKeyboardEvent(input, text[i++], 'keypress');
  triggerKeyboardEvent(input, text[i++], 'keyup');
  setTimeout(a, 50 * Math.random());
}
a();
