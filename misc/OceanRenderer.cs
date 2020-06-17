using System;
using System.Runtime.InteropServices;

using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace Ocean
{
    public class OceanRenderer : IDisposable
    {
        [DllImport("x86\\Ocean.Core.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "AllocateOceanRenderer", ExactSpelling = true)]
        private static extern IntPtr AllocateOceanRenderer(IntPtr oceanPtr, IntPtr bufferPtr);

        [DllImport("x86\\Ocean.Core.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "DrawOcean", ExactSpelling = true)]
        private static extern void DrawOcean(IntPtr oceanRendererPtr, IntPtr bufferPtr);

        [DllImport("x86\\Ocean.Core.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "FreeOceanRenderer", ExactSpelling = true)]
        private static extern void FreeOceanRenderer(IntPtr oceanRendererPtr);

        [DllImport("x64\\Ocean.Core.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "AllocateOceanRenderer", ExactSpelling = true)]
        private static extern IntPtr AllocateOceanRenderer64(IntPtr oceanPtr, IntPtr bufferPtr);

        [DllImport("x64\\Ocean.Core.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "DrawOcean", ExactSpelling = true)]
        private static extern void DrawOcean64(IntPtr oceanRendererPtr, IntPtr bufferPtr);

        [DllImport("x64\\Ocean.Core.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "FreeOceanRenderer", ExactSpelling = true)]
        private static extern void FreeOceanRenderer64(IntPtr oceanRendererPtr);

        private const byte c_emptyCellMarker = (byte)'\0';
        private const byte c_rockMarker = (byte)'R';
        private const byte c_seaweedMarker = (byte)'W';
        private const byte c_herbivorousFishMarker = (byte)'H';
        private const byte c_carnivorousFishMarker = (byte)'C';

        private static readonly Color s_emptyCellMarkerColor = Color.Black;
        private static readonly Color s_rockMarkerColor = Color.DarkGray;
        private static readonly Color s_seaweedMarkerColor = Color.Lime;
        private static readonly Color s_herbivorousFishMarkerColor = Color.Yellow;
        private static readonly Color s_carnivorousFishMarkerColor = Color.Red;

        private readonly bool m_use64BitApi;
        private readonly int m_screenWidth;
        private readonly int m_screenHeight;
        private readonly int m_width;
        private readonly int m_height;
        private readonly byte[] m_buffer;
        private readonly Color[] m_colorBuffer;
        private readonly GraphicsDevice m_graphicsDevice;
        private readonly SpriteBatch m_spriteBatch;
        private readonly Texture2D m_texture;
        private readonly IntPtr m_oceanPtr;
        private bool m_disposed;

        public IntPtr OceanRendererPtr { get; private set; }

        public OceanRenderer(int screenWidth, int screenHeight, Ocean ocean, GraphicsDevice graphicsDevice)
        {
            m_use64BitApi = Environment.Is64BitProcess;
            m_screenWidth = screenWidth;
            m_screenHeight = screenHeight;
            m_width = ocean.Width;
            m_height = ocean.Height;
            m_buffer = new byte[m_width * m_height];
            m_colorBuffer = new Color[m_width * m_height];
            m_graphicsDevice = graphicsDevice;
            m_spriteBatch = new SpriteBatch(graphicsDevice);
            m_texture = new Texture2D(graphicsDevice, m_width, m_height);
            m_oceanPtr = ocean.OceanPtr;
            m_disposed = false;
            OceanRendererPtr = m_use64BitApi ? AllocateOceanRenderer64(m_oceanPtr, IntPtr.Zero) : AllocateOceanRenderer(m_oceanPtr, IntPtr.Zero);
        }

        ~OceanRenderer() => Dispose(false);

        protected virtual void Dispose(bool disposeManagedResources)
        {
            if (!m_disposed)
            {
                if (disposeManagedResources)
                {
                    m_spriteBatch.Dispose();
                    m_texture.Dispose();
                }

                if (m_use64BitApi)
                    FreeOceanRenderer64(OceanRendererPtr);
                else
                    FreeOceanRenderer(OceanRendererPtr);

                OceanRendererPtr = IntPtr.Zero;
                m_disposed = true;
            }
        }

        public unsafe void Draw()
        {
            fixed (byte* bufferPtr = m_buffer)
            {
                if (m_use64BitApi)
                    DrawOcean64(OceanRendererPtr, (IntPtr)bufferPtr);
                else
                    DrawOcean(OceanRendererPtr, (IntPtr)bufferPtr);
            }

            for (int i = 0; i < m_buffer.Length; i++)
            {
                m_colorBuffer[i] = m_buffer[i] switch
                {
                    c_emptyCellMarker => s_emptyCellMarkerColor,
                    c_rockMarker => s_rockMarkerColor,
                    c_seaweedMarker => s_seaweedMarkerColor,
                    c_herbivorousFishMarker => s_herbivorousFishMarkerColor,
                    c_carnivorousFishMarker => s_carnivorousFishMarkerColor,
                    _ => throw new InvalidOperationException("The buffer was not filled correcty.")
                };
            }

            m_texture.SetData(m_colorBuffer);

            m_spriteBatch.Begin(samplerState: SamplerState.PointClamp);
            m_spriteBatch.Draw(m_texture, new Rectangle(0, 0, m_screenWidth, m_screenHeight), Color.White);
            m_spriteBatch.End();
        }

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
    }
}
