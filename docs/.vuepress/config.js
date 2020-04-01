module.exports = {
  title: 'Object Oriented Programming with C++',
  description: 'C++ Programming Course for VIVES University of Applied Sciences (Bachelor Degree)',
  themeConfig: {
    nav: [
    ],
    sidebar: [
      {
        title: 'About this Course',   // required
        // path: '/foo/',      // optional, which should be a absolute path.
        collapsable: true, // optional, defaults to true
        sidebarDepth: 1,    // optional, defaults to 1
        children: [
          ''
        ]
      },
      {
        title: 'Introduction to C++',   // required
        // path: '/foo/',      // optional, which should be a absolute path.
        collapsable: false, // optional, defaults to true
        sidebarDepth: 1,    // optional, defaults to 1
        children: [
          '01-hello-world/',
          '02-basics-of-cpp-in-a-nutshell/',
        ]
      },
      {
        title: 'Object Oriented Thinking',   // required
        path: '/03-object-oriented-thinking/',      // optional, which should be a absolute path.
        collapsable: false, // optional, defaults to true
        children: [
          '/03-object-oriented-thinking/',
          '/03-object-oriented-thinking/abstraction/',
          '/03-object-oriented-thinking/all_about_objects/',
        ]
      },
      {
        title: 'Basic OOP',   // required
        // path: '/foo/',      // optional, which should be a absolute path.
        collapsable: false, // optional, defaults to true
        sidebarDepth: 1,    // optional, defaults to 1
        children: [
          '04-basics-of-classes/',
          '05-composition/',
        ]
      },
      {
        title: 'Compilation',   // required
        // path: '/foo/',      // optional, which should be a absolute path.
        collapsable: false, // optional, defaults to true
        sidebarDepth: 1,    // optional, defaults to 1
        children: [
          '06-the-compilation-process/',
        ]
      },
      {
        title: 'Memory',   // required
        // path: '/foo/',      // optional, which should be a absolute path.
        collapsable: false, // optional, defaults to true
        sidebarDepth: 1,    // optional, defaults to 1
        children: [
          '07-pointers/',
          '08-dynamic-memory-allocation/',
        ]
      },
      {
        title: 'Working with Files',   // required
        // path: '/foo/',      // optional, which should be a absolute path.
        collapsable: false, // optional, defaults to true
        sidebarDepth: 1,    // optional, defaults to 1
        children: [
          '09-file-streams/',
        ]
      },
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
    }],
    ['container', {
      type: 'codeurl',
      defaultTitle: '💰 Full Code can be found at',
    }]
  ],
}