import clr
clr.AddReference("System.Drawing")
clr.AddReference("System.Windows.Forms")
clr.AddReference("Microsoft.DirectX.Direct3D")

from System.Drawing import *
from System.Windows.Forms import *
from Microsoft.DirectX.Direct3D import *


class CreateDevice(Form):
    def __init__(self):
        self.ClientSize = Size(400, 300)
        self.Text = "D3D Tutorial 01: CreateDevice"
        self.device = None
        
        self.Paint += lambda *_: self.render()
        self.initializeGraphics()


    def initializeGraphics(self):
        presentParams = PresentParameters()
        presentParams.Windowed = True
        presentParams.SwapEffect = SwapEffect.Discard

        self.device = Device(0, DeviceType.Hardware, self, 
                             CreateFlags.SoftwareVertexProcessing, 
                             presentParams)


    def render(self):
        if not self.device:
            return

        self.device.Clear(ClearFlags.Target, Color.Blue, 1.0, 0)

        self.device.BeginScene()

        # Here is where you put
        # Your code

        self.device.EndScene()
        self.device.Present()


frm = CreateDevice()
Application.Run(frm)