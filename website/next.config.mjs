import nextra from "nextra";

const withNextra = nextra({
    search: true,
    defaultShowCopyCode: true,
});

const isProd = process.env.NODE_ENV === 'production'

/** @type {import('next').NextConfig} */
const nextConfig = {
  output: 'export', // needed for static export with Next 13+
  basePath: isProd ? '/c_traceback' : '',
  assetPrefix: isProd ? '/c_traceback/' : '',
}

export default withNextra(nextConfig);
