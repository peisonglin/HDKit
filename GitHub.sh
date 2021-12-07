

#!/bin/sh
#  pod repo push $target_Name.podspec --allow-warnings
target_Name="HDKit"
path="/Users/Air/PSL/Github_HDKit/HDKitSpec"

if [ -d "${path}" ]
then
  cd $path
  pod trunk push $target_Name.podspec --allow-warnings
  
else
 echo "pod文件不存在"
fi

echo '完成'





