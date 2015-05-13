camera
{
	location <10,10,510> // la position de l'observateur
	look_at <510,10,510>  // le point de vue
	//right x*image_width/image_height	// aspect ratio
	//angle 45 // l'angle de la caméra
}

light_source { <1500,-550,500>
      color rgb<1,1,1>*0.8
}

sphere { <2000,-410,500>, 200 // coord centre et rayon
         pigment { color rgb <1,0,0> }
}

sphere { <5000,10,10>, 2000 // coord centre et rayon
         pigment { color rgb <1,1,0> }
}

sphere { <1500,10,800>, 200 // coord centre et rayon
         pigment { color rgb <1,0,1> }
}

sphere { <1500,-310,800>, 200 // coord centre et rayon
         pigment { color rgb <1,0,1> }
}
