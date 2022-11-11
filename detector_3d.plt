set terminal png
set terminal png size 800,800
set output "detector_3d.png"
set xlabel "Height"
set ylabel "Detected Particles"
plot "detector_3d.txt" with points pt 7 ps var