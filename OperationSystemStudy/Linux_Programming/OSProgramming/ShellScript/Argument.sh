#~/bin/sh
#입려된 인자 값
echo $#
#쉘 스크립트 파일 실행 명령어

if [ "a" == "$1" ]; then
	echo "1"
elif [ "b" == "$2" ]; then
	echo "2"
else 
	echo "0"
fi


