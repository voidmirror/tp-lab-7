using System;
using System.Runtime.InteropServices;

namespace Ocean
{
    public static class Program
    {
        [DllImport("x86\\Ocean.Core.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SetRandomSeed", ExactSpelling = true)]
        private static extern IntPtr SetRandomSeed(int seed);

        [DllImport("x64\\Ocean.Core.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SetRandomSeed", ExactSpelling = true)]
        private static extern IntPtr SetRandomSeed64(int seed);

        [STAThread]
        private static void Main()
        {
            if (Environment.Is64BitProcess)
                SetRandomSeed64(Environment.TickCount);
            else
                SetRandomSeed(Environment.TickCount);

            using (OceanGame game = new OceanGame())
                game.Run();
        }
    }
}
