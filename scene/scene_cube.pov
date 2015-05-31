camera
{
	location <0,200,200> // la position de l'observateur
	look_at <1000,100,100>  // le point de vue
}

light_source { <100, -200,0>
		color rgb<1,1,1>
}

plane { <-1,0,0>,3000 // coord centre et rayon
         pigment { color rgb <0,0,1> }
}


// ------------- cube start ------------
triangle { <500,0,0>, <0, 0.01, 0>, <0, 0, 0.01> // coord, u, v
		 pigment { color rgb <0,1,0> }
		 finish {specular 1}
}
triangle { <500,100,100>, <0, -0.01, 0>, <0, 0, -0.01> // coord, u, v
		 pigment { color rgb <1,0.6,0> }
		 finish {specular 1}
}

triangle { <600,0,0>, <0, 0.01, 0>, <0, 0, 0.01> // coord, u, v
		 pigment { color rgb <1,0,0> }
}
triangle { <600,100,100>, <0, -0.01, 0>, <0, 0, -0.01> // coord, u, v
		 pigment { color rgb <1,0,0> }
}

triangle { <600,0,0>, <-0.01, 0, 0>, <0, 0, 0.01> // coord, u, v
		 pigment { color rgb <0,0,1> }
}
triangle { <500,0,100>, <0.01,0,0>, <0, 0, -0.01> // coord, u, v
		 pigment { color rgb <0,0,1> }
}

triangle { <600,100,0>, <-0.01, 0, 0>, <0, 0, 0.01> // coord, u, v
		 pigment { color rgb <0,1,0> }
}
triangle { <500,100,100>, <0.01, 0, 0>, <0, 0, -0.01> // coord, u, v
		 pigment { color rgb <0,1,0> }
}

triangle { <500,0,0>, <0.01, 0, 0>, <0, 0.01, 0> // coord, u, v
		 pigment { color rgb <0,1,1> }
}
triangle { <600,100,0>, <-0.01, 0, 0>, <0, -0.01, 0> // coord, u, v
		 pigment { color rgb <0,1,1> }
}

triangle { <500,0,100>, <0.01, 0, 0>, <0, 0.01, 0> // coord, u, v
		 pigment { color rgb <0,1,1> }
}
triangle { <600,100,100>, <-0.01, 0, 0>, <0, -0.01, 0> // coord, u, v
		 pigment { color rgb <0,1,1> }
}
// ----------------- cube end ------------