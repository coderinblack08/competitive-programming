const duplicateEncode = (word) => {
  const duplicates = {};
  let result = '';
  for (let i = 0; i < word.length; i++) {
    if (duplicates.hasOwnProperty(word[i].toLowerCase())) {
      duplicates[word[i].toLowerCase()]++;
    } else {
      duplicates[word[i].toLowerCase()] = 1;
    }
  }
  for (let i = 0; i < word.length; i++) {
    if (duplicates[word[i].toLowerCase()] === 1) {
      result += '(';
    } else {
      result += ')';
    }
  }
  return result;
};
