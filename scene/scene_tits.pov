camera
{
	location <0,0,0> // la position de l'observateur
	look_at <1000,0,0>  // le point de vue
}

light_source { <1000,1500,-1000>
		color rgb<1,1,1>
}

plane { <-1,0,0>,3000 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         finish {reflection 1.0}
}
plane { <0,1,0>,3000 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         finish {reflection 1.0}
}
plane { <0,0,1>,3000 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         finish {reflection 1.0}
}
plane { <0,0,-1>,1000 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         finish {reflection 1.0}
}
plane { <0,-1,0>,3000 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         finish {reflection 1.0}
}
plane { <1,0,0>,3000 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         finish {reflection 1.0}
}

sphere { <3000,280,1000>, 400 // coord centre et rayon
         pigment { color rgb <1,0.8,0.75> }
         finish {specular 1}
}

sphere { <3000,-280,1000>, 400 // coord centre et rayon
         pigment { color rgb <1,0.8,0.75> }
         finish {specular 1}
}

sphere { <3000,280,740>, 150 // coord centre et rayon
         pigment { color rgb <1,0.6,0.55> }
         finish {specular 1}
}

sphere { <3000,-280,740>, 150 // coord centre et rayon
         pigment { color rgb <1,0.6,0.55> }
         finish {specular 1}
}

sphere { <3000,280,610>, 30 // coord centre et rayon
         pigment { color rgb <1,0.6,0.55> }
         finish {specular 1}
}

sphere { <3000,-280,610>, 30 // coord centre et rayon
         pigment { color rgb <1,0.6,0.55> }
         finish {specular 1}
}
