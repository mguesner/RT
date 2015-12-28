camera
{
	location <-500,0,-500> // la position de l'observateur
	look_at <1000,0,0>  // le point de vue
}

light_source { <300, 100,0>
		color rgb<1,1,1>
}


sphere { <550,48,-300>, 75 // coord centre et rayon
         pigment { color rgb <0,1,0> }
         finish {reflection 1}
}

plane { <0,0,-1>,200 // plane mur sol
        // pigment { color rgb <0,1,0> }
        texture { name damier2 }
}
cylinder_42 { <550,48,0>, <0,0,1>, 20 // coord, direction, rayon
         pigment { color rgb <0,0.6,0.6> }
         finish {refraction 10 transparence 1}
         end 150 2000
}



// ------------- cube start ------------
triangle { <500,0,150>, <0, 0.01, 0>, <0, 0, 0.01> // coord, u, v
		 pigment { color rgb <0,0.6,0.6> }
}
triangle { <500,100,250>, <0, -0.01, 0>, <0, 0, -0.01> // coord, u, v
		 pigment { color rgb <0,0.6,0.6> }
}

triangle { <600,0,150>, <0, 0.01, 0>, <0, 0, 0.01> // coord, u, v
		 pigment { color rgb <0,1,0> }
}
triangle { <500,100,250>, <0, -0.01, 0>, <0, 0, -0.01> // coord, u, v
		 pigment { color rgb <0,1,0> }
}

triangle { <600,0,150>, <-0.01, 0, 0>, <0, 0, 0.01> // coord, u, v
		 pigment { color rgb <0,1,0> }
}
triangle { <500,0,250>, <0.01,0,0>, <0, 0, -0.01> // coord, u, v
		 pigment { color rgb <0,1,0> }
}

triangle { <600,100,150>, <-0.01, 0, 0>, <0, 0, 0.01> // coord, u, v
		 pigment { color rgb <0,1,0> }
}
triangle { <500,100,250>, <0.01, 0, 0>, <0, 0, -0.01> // coord, u, v
		 pigment { color rgb <0,1,0> }
}

triangle { <500,0,150>, <0.01, 0, 0>, <0, 0.01, 0> // coord, u, v
		 pigment { color rgb <0,1,0> }
}
triangle { <600,100,150>, <-0.01, 0, 0>, <0, -0.01, 0> // coord, u, v
		 pigment { color rgb <0,1,0> }
}


// ----------------- cube end ------------
