camera
{
	location <10,10,510> // la position de l'observateur
	look_at <510,10,510>  // le point de vue
	//right x*image_width/image_height	// aspect ratio
	//angle 45 // l'angle de la caméra
}

<<<<<<< HEAD
light_source { <3,-2,4>
		color rgb<1,1,1>
}

light_source { <3.2,-2,4>
      color rgb<1,1,1>
}

light_source { <3.5,-2,4>
      color rgb<1,1,1>
=======
light_source { <2030,1010,510>
      color rgb<1,1,1>*0.8
}

sphere { <2030,10,510>, 200 // coord centre et rayon
         pigment { color rgb <1,0,0> }
>>>>>>> 1178125faa01bf35a2c4b197b1f448ee537fac51
}

plane { <0,0,1>, 1000 // coord centre et rayon
         pigment { color rgb <1,1,0> }
}

<<<<<<< HEAD
plane { <5,5,0>, 10
         pigment { color rgb <1,0.6,0> }
}
=======
>>>>>>> 1178125faa01bf35a2c4b197b1f448ee537fac51
