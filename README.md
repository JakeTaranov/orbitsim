In an attempt to learn C++ I created a program to simulate orbits of celestial bodies.

## Input

The program reads in a json file with the attributes of N bodies in the form of:

```json
{
  "bodies": [
    {
      "mass": 10000,
      "radius": 10,
      "pos_x": 600,
      "pos_y": 400,
      "vel_x": 0.5,
      "vel_y": 1.5,
      "drawline": true
    },
    {
      "mass": 10000,
      "radius": 10,
      "pos_x": 1000,
      "pos_y": 450,
      "vel_x": -0.5,
      "vel_y": -1.5,
      "drawline": true
    }
  ],
  "stay_in_bounds": true
}
```
Above is an example taken from ```stable_orbit.json``` 

<ul>
  <li><b>mass<\b>: (int) mass of body n</l1>
</ul>



