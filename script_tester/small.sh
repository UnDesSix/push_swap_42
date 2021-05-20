a=22
v="24"

v=`expr $v + 0`

if [ "$a" -lt "$v" ] ;
then
a="$v"
echo $a
fi
