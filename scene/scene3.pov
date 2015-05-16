camera
{
	location <10,10,510> // la position de l'observateur
	look_at <510,10,510>  // le point de vue
	//right x*image_width/image_height	// aspect ratio
	//angle 45 // l'angle de la caméra
}

light_source { <2030,510,1020>
      color rgb<1,1,1>
}

light_source { <2030,-490,1020>
      color rgb<1,1,1>
}

light_source { <2030,510,-20>
      color rgb<1,1,1>
}

light_source { <2030,-490,-20>
      color rgb<1,1,1>
}

light_source { <1530,1020,500>
      color rgb<1,1,1>
}

light_source { <2530,1020,500>
      color rgb<1,1,1>
}

light_source { <1530,-1020,500>
      color rgb<1,1,1>
}

light_source { <2530,-1020,500>
      color rgb<1,1,1>
}

light_source { <3020,-520,500>
      color rgb<1,1,1>
}

light_source { <3020,520,500>
      color rgb<1,1,1>
}

light_source { <1020,510,500>
      color rgb<1,1,1>
}

sphere { <1500,125,-10>, 170 // coord centre et rayon
         pigment { color rgb <1,0.7,0.7> }
}

sphere { <1500,-125,-10>, 170 // coord centre et rayon
         pigment { color rgb <1,0.7,0.7> }
}

sphere { <1500,125,137>, 30 // coord centre et rayon
         pigment { color rgb <1,0.5,0.5> }
}

sphere { <1500,-125,13>, 30 // coord centre et rayon
         pigment { color rgb <1,0.5,0.5> }
}


plane { <0,1,0>,  1000// coord centre et rayon
         pigment { color rgb <0,1,0> }
}

plane { <0,0,1>, 0 // coord centre et rayon
         pigment { color rgb <1,1,0> }
}

plane { <-1,0,0>, 2000// coord centre et rayon
         pigment { color rgb <0,0,1> }
}

plane { <0,-1,0>,  1000// coord centre et rayon
         pigment { color rgb <1,0,1> }
}

plane { <0,0,-1>,  1000// coord centre et rayon
         pigment { color rgb <1,0,0> }
}
