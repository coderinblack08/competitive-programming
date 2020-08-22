const longest = (s1, s2) => {
  return [...new Set(s1 + s2)].sort().join('');
};
