module.exports = {
  title: 'Object Oriented Programming with C++',
  description: 'C++ Programming Course for VIVES University of Applied Sciences (Bachelor Degree)',
  themeConfig: {
    nav: [
    ],
    sidebar: [
        '01-hello-world/',
        '02-basics-of-cpp-in-a-nutshell/',
        {
          title: '03 - Object Oriented Thinking',   // required
          path: '/03-object-oriented-thinking/',      // optional, which should be a absolute path.
          children: [
            '/03-object-oriented-thinking/',
            '/03-object-oriented-thinking/abstraction/',
            '/03-object-oriented-thinking/all_about_objects/',
          ]
        },
        '04-basics-of-classes/',
        '05-composition/',
    ],
    sidebarDepth: 1,
    repo: 'BioBoost/course-object-oriented-programming-with-cpp',
    docsDir: 'docs',
    docsBranch: 'master'
  },
  markdown: {
    lineNumbers: true,
  },
  serviceWorker: true,
  plugins: [
    ['vuepress-plugin-zooming', {
      // selector for images that you want to be zoomable
      // default: '.content img'
      selector: 'img',

      // make images zoomable with delay after entering a page
      // default: 500
      // delay: 1000,

      // options of zooming
      // default: {}
      options: {
        bgColor: 'black',
        zIndex: 10000,
      },
    }],
    ['container', {
      type: 'codeoutput',
      defaultTitle: 'Output',
    }]
  ],
}