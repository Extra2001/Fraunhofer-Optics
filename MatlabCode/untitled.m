x = 0:100;
h = -0.2*0.8.^x;
h(1) = h(1)+1;
img=checkerboard(12);
img(img>0.5)=1;
img = filter(h, 1, img);
img = img';
img = filter(h, 1, img);
img = img';
imagesc(img)