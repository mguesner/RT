camera
{
	location <10,10,510> // la position de l'observateur
	look_at <510,10,510>  // le point de vue
	//right x*image_width/image_height	// aspect ratio
	//angle 45 // l'angle de la caméra
}

light_source { <2030,510,1200>
      color rgb<1,1,1>
}

light_source { <2030,-490,1200>
      color rgb<1,1,1>
}

light_source { <2030,10,1800>
      color rgb<1,1,1>
}

sphere { <2030,10,110>, 200 // coord centre et rayon
         pigment { color rgb <1,0,0> }
}

plane { <0,0,1>, 1 // coord centre et rayon
         pigment { color rgb <1,1,0> }
}
