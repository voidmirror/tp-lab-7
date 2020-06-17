using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;

namespace Ocean
{
    public class OceanGame : Game
    {
        private const bool c_isFullScreen = true;
        private const int c_windowWidth = 1280;
        private const int c_windowHeight = 720;
        private const int c_oceanWidth = c_windowWidth / 4;
        private const int c_oceanHeight = c_windowHeight / 4;

        private Ocean m_ocean;
        private OceanRenderer m_oceanRenderer;
        private bool m_disposed;

        protected GraphicsDeviceManager GraphicsDeviceManager { get; }

        public OceanGame()
        {
            m_ocean = null;
            m_oceanRenderer = null;
            m_disposed = false;
            GraphicsDeviceManager = new GraphicsDeviceManager(this)
            {
                HardwareModeSwitch = true,
                IsFullScreen = c_isFullScreen,
                PreferredBackBufferWidth = c_windowWidth,
                PreferredBackBufferHeight = c_windowHeight
            };
            IsMouseVisible = true;
            IsFixedTimeStep = true;
            TargetElapsedTime = TimeSpan.FromSeconds(1) / 25;
        }

        protected override void LoadContent()
        {
            m_ocean = new Ocean(c_oceanWidth, c_oceanHeight);
            m_oceanRenderer = new OceanRenderer(c_windowWidth, c_windowHeight, m_ocean, GraphicsDevice);
            base.LoadContent();
        }

        protected override void Update(GameTime gameTime)
        {
            if (Keyboard.GetState().IsKeyDown(Keys.Escape))
                Exit();

            m_ocean.Update();

            base.Update(gameTime);
        }
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.Black);

            m_oceanRenderer.Draw();

            base.Draw(gameTime);
        }

        protected override void Dispose(bool disposeManagedResources)
        {
            if (!m_disposed && disposeManagedResources)
            {
                if (disposeManagedResources)
                {
                    m_ocean?.Dispose();
                    m_oceanRenderer?.Dispose();
                }

                m_disposed = true;
            }

            base.Dispose(disposeManagedResources);
        }
    }
}
