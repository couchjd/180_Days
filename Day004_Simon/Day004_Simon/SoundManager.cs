using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Media;
using System.Text;
using System.Threading.Tasks;

namespace Day004_Simon {
  class SoundManager {
    public SoundPlayer greenSound, redSound, yellowSound, blueSound, failSound;
    public SoundManager() {
      string dir = Directory.GetParent(Directory.GetParent(Directory.GetCurrentDirectory()).ToString()).ToString();
      greenSound = new SoundPlayer(dir + @"\res\sounds\simonSound1.wav");
      redSound = new SoundPlayer(dir + @"\res\sounds\simonSound2.wav");
      yellowSound = new SoundPlayer(dir + @"\res\sounds\simonSound3.wav");
      blueSound = new SoundPlayer(dir + @"\res\sounds\simonSound4.wav");
      failSound = new SoundPlayer(dir + @"\res\sounds\blurp_x.wav");
    }
  }
}
