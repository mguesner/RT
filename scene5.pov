camera
{
   location <0,0,0>
   look_at <1000,0,0>
}

light_source { <300, 100,0>
		color rgb<1,1,1>
}

plane { <-1,0,0>,9500 // coord centre et rayon
         pigment { color rgb <1,1,1> }
}

sphere { <2000,-600,-600>, 200 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         finish {transparence 0.1
         refraction 1.33}
}

sphere { <2000,0,-600>, 200 // coord centre et rayon
         pigment { color rgb <0,1,0> }
         finish {transparence 0.2
         refraction 1.33}
}

sphere { <2000,600,-600>, 200 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {transparence 0.3
         refraction 1.33}
}

sphere { <2000,-600,0>, 200 // coord centre et rayon
         pigment { color rgb <1,1,0> }
         finish {transparence 0.4
         refraction 1.33}
}

sphere { <2000,0,0>, 200 // coord centre et rayon
         pigment { color rgb <1,0,1> }
         finish {transparence 0.5
         refraction 1.33}
}

sphere { <2000,600,0>, 200 // coord centre et rayon
         pigment { color rgb <0,1,1> }
         finish {transparence 0.6
         refraction 1.33}
}

sphere { <2000,-600,600>, 200 // coord centre et rayon
         pigment { color rgb <0.5,0.5,1> }
         finish {transparence 0.7
         refraction 1.33}
}

sphere { <2000,0,600>, 200 // coord centre et rayon
         pigment { color rgb <1,0.5,1> }
         finish {transparence 0.8
         refraction 1.33}
}

sphere { <2000,600,600>, 200 // coord centre et rayon
         pigment { color rgb <0.5,0.1,0.9> }
         finish {transparence 0.9
         refraction 1.33}
}
