camera
{
	location <10,10,510> // la position de l'observateur
	look_at <510,10,510>  // le point de vue
	//right x*image_width/image_height	// aspect ratio
	//angle 45 // l'angle de la caméra
}

light_source { <3,-2,4>
		color rgb<1,1,1>*0.8
}

light_source { <3.2,-2,4>
      color rgb<1,1,1>*0.8
}

light_source { <3.5,-2,4>
      color rgb<1,1,1>*0.8
}

sphere { <5000,10,1000>, 400 // coord centre et rayon
         pigment { color rgb <1,0,0> }
}

sphere { <5000,810,1000>, 400 // coord centre et rayon
         pigment { color rgb <1,0,0> }
}
