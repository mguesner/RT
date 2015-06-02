camera
{
	location <0,0,0> // la position de l'observateur
	look_at <1000,0,0>  // le point de vue
	//right x*image_width/image_height	// aspect ratio
	//angle 45 // l'angle de la caméra
}

light_source { <1000,0,0>
      color rgb<1,1,1>
}

sphere { <2000,130,1020>, 200 // coord centre et rayon
         pigment { color rgb <1,0.8,0.70> }
}

sphere { <2000,-130,1020>, 200 // coord centre et rayon
         pigment { color rgb <1,0.8,0.70> }
}

sphere { <2000,130,893>, 80 // coord centre et rayon
		pigment { color rgb <1,0.3,0.2> }

}

sphere { <2000,-130,893>, 80 // coord centre et rayon
		pigment { color rgb <1,0.3,0.2> }
}

sphere { <2000,130,818>, 10 // coord centre et rayon
		pigment { color rgb <1,0.3,0.2> }

}

sphere { <2000,-130,818>, 10 // coord centre et rayon
		pigment { color rgb <1,0.3,0.2> }
}

plane { <0,0,1>,2000 // coord centre et rayon
        pigment { color rgb <1,1,1> }

}

plane { <0,0,-1>,1000 // coord centre et rayon
        pigment { color rgb <1,1,1> }
}

plane { <1,0,0>,4000 // coord centre et rayon
        pigment { color rgb <1,1,1> }
        finish {reflection 1}
}

plane { <-1,0,0>,4000 // coord centre et rayon
        pigment { color rgb <1,1,1> }
        finish {reflection 1}
}

plane { <0,1,0>,2000 // coord centre et rayon
        pigment { color rgb <1,1,1> }

}

plane { <0,-1,0>,2000 // coord centre et rayon
        pigment { color rgb <1,1,1> }

}

//254 | 195 | 172
