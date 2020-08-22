const reverseLetter = (str) => {
  str = str.split``.filter(
    (char) =>
      (65 <= char.charCodeAt(0) && 90 >= char.charCodeAt(0)) ||
      (97 <= char.charCodeAt(0) && 122 >= char.charCodeAt(0))
  );
  return str.reverse().join``;
};

// const reverseLetter = (str) =>
//   str
//     .replace(/[^a-z]/gi, '')
//     .split('')
//     .reverse()
//     .join('');

console.log(reverseLetter('krishan'), 'nahsirk');

console.log(reverseLetter('ultr53o?n'), 'nortlu');

console.log(reverseLetter('ab23c'), 'cba');

console.log(reverseLetter('krish21an'), 'nahsirk');
