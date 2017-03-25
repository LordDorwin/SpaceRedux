//junk.cpp
//Temporary code storage





//Apply thrust to heading (accounting for time spent in frame
//printf("%d", frameTime);
printf("pre: %lf, %lf\n", heaVecX, heaVecY);
heaVecX = (heaVecX / frameTime) + thrVecX;
heaVecY = (heaVecY / frameTime) + thrVecY;
printf("post: %lf, %lf\n", heaVecX, heaVecY);

//Calculate resulting heading
heaSpeed = sqrt((heaVecX*heaVecX) + (heaVecY*heaVecY));
heaDir = radDeg(acos(heaVecX / heaSpeed));

//Limit speed
if (heaSpeed > maxSpeed) {
	heaVecX = maxSpeed * radDeg(abs(cos(heaDir))) * sign(thrVecX);
	heaVecY = maxSpeed * radDeg(abs(sin(heaDir))) * sign(thrVecY);
	printf("shits fucked");
}
printf("%lf,  %lf\n", thrVecX, thrVecY);
printf("%lf,  %lf\n", heaVecX, heaVecY);
printf("\n");

//Apply speed
_x += heaVecX * frameTime;
_y += heaVecY * frameTime;

//Reset thrust vectors
thrVecX = 0, thrVecY = 0;