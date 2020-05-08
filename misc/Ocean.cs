using System;
using System.Runtime.InteropServices;

namespace Ocean
{
    public class Ocean : IDisposable
    {
        [DllImport("x86\\Ocean.Core.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "AllocateOcean", ExactSpelling = true)]
        private static extern IntPtr AllocateOcean(int width, int height);

        [DllImport("x86\\Ocean.Core.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "UpdateOcean", ExactSpelling = true)]
        private static extern void UpdateOcean(IntPtr oceanPtr);

        [DllImport("x86\\Ocean.Core.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "FreeOcean", ExactSpelling = true)]
        private static extern void FreeOcean(IntPtr oceanPtr);

        [DllImport("x64\\Ocean.Core.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "AllocateOcean", ExactSpelling = true)]
        private static extern IntPtr AllocateOcean64(int width, int height);

        [DllImport("x64\\Ocean.Core.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "UpdateOcean", ExactSpelling = true)]
        private static extern void UpdateOcean64(IntPtr oceanPtr);

        [DllImport("x64\\Ocean.Core.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "FreeOcean", ExactSpelling = true)]
        private static extern void FreeOcean64(IntPtr oceanPtr);

        private readonly bool m_use64BitApi;
        private bool m_disposed;

        public int Width { get; }
        public int Height { get; }

        public IntPtr OceanPtr { get; private set; }

        public Ocean(int width, int height)
        {
            m_use64BitApi = Environment.Is64BitProcess;
            m_disposed = false;
            Width = width;
            Height = height;
            OceanPtr = m_use64BitApi ? AllocateOcean64(width, height) : AllocateOcean(width, height);
        }

        ~Ocean() => Dispose(false);

        protected virtual void Dispose(bool disposeManagedResources)
        {
            if (!m_disposed)
            {
                if (m_use64BitApi)
                    FreeOcean64(OceanPtr);
                else
                    FreeOcean(OceanPtr);

                OceanPtr = IntPtr.Zero;
                m_disposed = true;
            }
        }

        public void Update()
        {
            if (m_use64BitApi)
                UpdateOcean64(OceanPtr);
            else
                UpdateOcean(OceanPtr);
        }

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
    }
}
