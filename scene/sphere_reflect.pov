camera
{
	location <0,0,0> // la position de l'observateur
	look_at <1000,0,0>  // le point de vue
}

light_source { <100, -100,0>
		color rgb<1,1,1>
}

sphere { <650,250,50>, 100 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {reflection 0.8}
}

sphere { <650,-350,50>, 100 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {reflection 0.8}
}


sphere { <650,-150,50>, 100 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {reflection 0.8}
}


sphere { <650,50,50>, 100 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {reflection 0.8}
}


sphere { <550,0,150>, 50 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {reflection 0.8}
}

sphere { <550,100,150>, 50 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {reflection 0.8}
}

sphere { <550,-100,150>, 50 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {reflection 0.8}
}

sphere { <550,-200,150>, 50 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {reflection 0.8}
}
sphere { <550,200,150>, 50 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {reflection 0.8}
}

sphere { <450,200,175>, 25 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {reflection 0.8}
}

sphere { <450,150,175>, 25 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {reflection 0.8}
}

sphere { <450,100,175>, 25 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {reflection 0.8}
}

sphere { <450,50,175>, 25 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {reflection 0.8}
}

sphere { <450,100,175>, 25 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {reflection 0.8}
}

sphere { <450,0,175>, 25 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {reflection 0.8}
}

sphere { <450,-50,175>, 25 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {reflection 0.8}
}

sphere { <450,-100,175>, 25 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {reflection 0.8}
}

sphere { <450,-150,175>, 25 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {reflection 0.8}
}

sphere { <450,-200,175>, 25 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {reflection 0.8}
}

plane { <0,0,-1>,200 // plane mur sol
        // pigment { color rgb <0,1,0> }
        texture { name damier2 }
}
