#!/bin/sh
#说明：
#该脚本用于提交LBLelink.framework和版本号的修改，需要先手动替换好LBLelink.framework
#然后执行： sh version.sh "$版本号"，比如： sh version.sh "30013"
#最后的提交和发布是高危的动作，所以设置为需要人为执行，操作步骤参考最后几条命令

old_version=`grep -r "s.version" LBLelinkKit.podspec  |grep -v "s.source" |awk -F "\"" '{print $2 }' `
echo old_version =$old_version
new_version=$1
[ "x$new_version" == "x" ] && echo "please input new version and exit" && exit 1
sed -i .tmp s/$old_version/$new_version/g LBLelinkKit.podspec #ios中的sed需要一个临时文件来转换
[ $? -ne 0 ] && echo "must run at ios system and so exit" && exit 1
rm *.tmp
git status
git diff LBLelinkKit.podspec
git add LBLelinkKit.podspec
git add LBLelinkKit.framework
git commit -m "update framework to $new_version and modify to version $new_version"
echo manual run following steps:
echo "step1: git push origin master"
echo "step2: git tag v$new_version"
echo "step3: git push origin v$new_version"
echo "step4: pod trunk push"
