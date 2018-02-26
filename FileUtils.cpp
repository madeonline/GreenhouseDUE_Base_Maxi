//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "FileUtils.h"
#include "ConfigPin.h"
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SdFat SD;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool SDInit::sdInitFlag = false;
bool SDInit::sdInitResult = false;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// FileUtils
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int FileUtils::CountFiles(const String& dirName)
{
  if(!SDInit::sdInitResult)
    return 0;

  int result = 0;
  SD.chdir("/LOGS");
  
  SdFile file;
  
  while (file.openNext(SD.vwd(), O_READ)) 
  {
    result++;
    file.close();
  }  

  return result;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool SDInit::InitSD()
{
  if(SDInit::sdInitFlag)
    return SDInit::sdInitResult;

  SDInit::sdInitFlag = true;
  SDInit::sdInitResult = SD.begin(SD_CS_PIN,SPI_HALF_SPEED);
  
  return SDInit::sdInitResult;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
FileEnumerator::FileEnumerator()
{
   currentPosition = 0;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
FileEnumerator::~FileEnumerator()
{
  close();
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool FileEnumerator::open(const String& directoryName)
{
    close();

    dirName = directoryName;
    root.open(dirName.c_str(),O_READ);
    
    return root.isOpen();
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void FileEnumerator::close()
{
   if(entry.isOpen())
    entry.close();
    
   if(root.isOpen())
    root.close();

    currentPosition = 0;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool FileEnumerator::first()
{
  if(!root.isOpen())
    return false;

  root.rewind();
  currentPosition = 0;
  
  return next();
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool FileEnumerator::next()
{
  if(!root.isOpen())
    return false;

  if(entry.isOpen())
    entry.close();

  currentPosition++;
  
  bool result = entry.open(&root,currentPosition,O_READ);
  if(!result)
  {
    --currentPosition;
    
    if(currentPosition > 0)
      entry.open(&root,currentPosition,O_READ);
  }

  return result;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool FileEnumerator::info(FileEntry& info)
{
  if(!entry.isOpen())
    return false;
    
  info.isDirectory = entry.isDir();

  static char nameBuff[15] = {0};
  entry.getName(nameBuff,15); 

  info.name = nameBuff;

  return true;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool FileEnumerator::prev()
{
  if(!root.isOpen())
    return false;  

  if(currentPosition < 2)
    return false;

   currentPosition -= 2;
           
   return next();
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

