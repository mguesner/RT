camera
{
	location <0,0,0> // la position de l'observateur
	look_at <1000,0,0>  // le point de vue
}

light_source { <1500,200,-1900>
		color rgb<1,1,1>
}

light_source { <1100,-400,-1900>
      color rgb<1,1,1>
}

light_source { <1900,800,-1900>
      color rgb<1,1,1>
}

plane { <0,0,-1>,1000 // coord centre et rayon
         pigment { color rgb <0.9,0.9,0.9> }
}

sphere { <2000,0,530>, 300 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         finish {specular 1}
}
