camera
{
	location <0,0,1> // la position de l'observateur
	look_at <1,0,1>  // le point de vue
	//right x*image_width/image_height	// aspect ratio
	//angle 45 // l'angle de la caméra
}

light_source { <3,-2,4>
		color rgb<1,1,1>
}

light_source { <3.2,-2,4>
      color rgb<1,1,1>
}

light_source { <3.5,-2,4>
      color rgb<1,1,1>
}

sphere { <2,-1,1>, 2 // coord centre et rayon
         pigment { color rgb <1,0.6,0> }
}

plane { <5,5,0>, 10
         pigment { color rgb <1,0.6,0> }
}
