set terminal png
set terminal png size 600,400
set output "radiation_3d.png"
set xlabel "X"
set ylabel "Y"
set zlabel "Z"
splot "radiation_3d.txt" with dots