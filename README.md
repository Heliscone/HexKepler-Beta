# HexKepler-Beta
Very beta print files and instructions for the HexKepler automated print ejection system for Bambulab Printers

I expect it'll be finalized earliest december, probably closer to new years! In fact, 1/1/2024 is my goal for publishing a fully-polished-everything. :) 

Hey there! This read-me is still being written, but here are very rudimentary assembly instructions. I recommend printing the parts in ABS as in the .3mf file. (The Short Arm especially)

**Cutting Leadscrews to Length**
Cut the 3ft of leadscrews from McMaster Carr to two pieces, one length 165+-3mm and the other 147+-8mm. Label the ~165mm leadscrew "A" and the ~147mm leadscrew "B".
**Putting in Leadscrew Nuts**
1. Push two leadscrew nuts into the Short Arm. This can be a little difficult, so I recomment using a hammer to gently tap in the first leadscrew nut, then doing similar to push in a second nut after the first. Then, firmly thread a leadscrew through (it may be difficult to turn, there will eventually be a _small_ gap between the leadscrew nuts. exaggerated in the image below)
   ![image](https://github.com/Heliscone/HexKepler-Beta/assets/58831250/b8a86b49-aa16-4ba1-8a04-b10e0933864c)
  Then, take out the leadscrew.
2. Do similarly for the Longarm. It might be easier to hammer it from the backside, gently. I'm still workingon a less painful way to get this done...
![image](https://github.com/Heliscone/HexKepler-Beta/assets/58831250/7e6eb1e7-9d97-4bca-8554-937ac05e982b)
3. Couple together Leadscrew **B** and one stepper motor. Be careful to tighten equally from both ends so the shaft doesn't wobble when it turns
![image](https://github.com/Heliscone/HexKepler-Beta/assets/58831250/1124e601-33c8-46c3-aa70-237cd9552881)
4. UseM3x12 screws to screw the motor-leadscrew-B assembly into the ShortArm
![image](https://github.com/Heliscone/HexKepler-Beta/assets/58831250/405f12d1-276e-4739-88fe-0fe50c62dbe4)
5. screw leadscrew B through the long arm
![image](https://github.com/Heliscone/HexKepler-Beta/assets/58831250/ccb3cf6e-fbba-4c8a-90a2-0feda45a99d1)
6. Use an M3x16screw and a nut to loosely attach the long arm's tip. That is, it should be loose enough to rotate, but tight enough to not flop around. (working on a way to make this... more repeatable.)
![image](https://github.com/Heliscone/HexKepler-Beta/assets/58831250/350ac8fa-aec6-4687-ae15-db0418112ae9)

Woo! You should now have something like this:
![image](https://github.com/Heliscone/HexKepler-Beta/assets/58831250/b4c756f5-6ef1-43ca-8c9d-8e7561f3050c)

7. Now, couple Leadscrew **A** and another stepper motor! Again, be careful to tighten them equally fromboth ends so the shaft doesn't wobble.
8. At last! Bring out the carriage. Note that the motor for leadscrew Ais the _left_ one here. slide leadscrew A through the hole of the carriage, then thread the leadscrew through the short arm. YOu should end up with something like this!
![image](https://github.com/Heliscone/HexKepler-Beta/assets/58831250/697ce3cb-c801-4011-816f-a661a5c9ce86)
9. Use M3x16 screws to screw the motor to the carriage. Lower the bed all the way tothe bottom, then scoot in the whole assembly:
![image](https://github.com/Heliscone/HexKepler-Beta/assets/58831250/4fa884c6-49f6-441f-af71-985ca45bbff3)
In the below image, use an M3x16mm screw for the left hole and an M3x12mm screw for the right hole:
![image](https://github.com/Heliscone/HexKepler-Beta/assets/58831250/0178dc58-4709-4e5e-ac87-d31dbe8db58b)






![image](https://github.com/Heliscone/HexKepler-Beta/assets/58831250/260f0912-8916-4f52-9ef7-a1f72cdddd6c)
