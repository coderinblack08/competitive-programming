const minOperations = (logs) => {
  let nestedFolders = 0;
  logs.forEach((log) => {
    if (log === '../') {
      nestedFolders--;
      nestedFolders = Math.max(0, nestedFolders);
    } else if (log !== './') {
      nestedFolders++;
    }
  });
  return Math.max(0, nestedFolders);
};
