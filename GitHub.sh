

#!/bin/sh

target_Name="HDObjectGitHub"
ClassesName="HDObject"

path="/Users/Air/.cocoapods/repos/$ClassesName"

if [ -d "${path}" ]
then
 pod repo update "$path"
fi




if [ -d "${path}" ]
then
  cd $path
#  pod trunk push $ClassesName $target_Name.podspec --allow-warnings
  pod repo push $ClassesName $target_Name.podspec --allow-warnings
  for i in `ls`;do
  if [ "$i" != $target_Name ]
     then
     rm -rf $i;
     else
         cd "`pwd`/$target_Name"
         for i in `ls`;do if [ "$i" = Classes -o "$i" = Assets -o "$i" = HDObject -o "$i" = HDObject.xcodeproj -o "$i" = HDObject.xcworkspace -o "$i" = Podfile ];then rm -rf $i;fi;done;
         cd $path
  fi;
  done;
else
 echo 'pod文件不存在'
fi




echo '完成'





