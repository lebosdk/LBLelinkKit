#!/bin/sh
old_version=`grep -r "s.version" LBLelinkKit.podspec  |grep -v "s.source" |awk -F "\"" '{print $2 }' `
echo old_version =$old_version
new_version=$1
[ "x$new_version" == "x" ] && echo "please input new version and exit" && exit 1
sed -i .tmp s/$old_version/$new_version/g LBLelinkKit.podspec #ios中的sed需要一个临时文件来转换
[ $? -ne 0 ] && echo "must run at ios system and so exit" && exit 1
rm *.tmp
git diff LBLelinkKit.podspec
git add LBLelinkKit.podspec
git commit -m "modify to version $new_version"
echo manual run following steps:
echo "step1: git push origin master"
echo "step2: git tag v$new_version"
echo "step3: git push origin v$new_version"
