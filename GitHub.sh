

#!/bin/sh
#  pod repo push $target_Name.podspec --allow-warnings
target_Name="HDKit"
path="/Users/peiwu/PSL/HDKitObject"

if [ -d "${path}" ]
then
  cd $path
  arch -x86_64 pod trunk push $target_Name.podspec --allow-warnings
  
else
 echo "podSpec文件不存在"
fi
 pod lib lint HDKit.podspec --allow-warnings --no-clean --verbose
echo '完成'





