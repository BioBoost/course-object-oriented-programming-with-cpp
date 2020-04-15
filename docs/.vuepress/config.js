module.exports = {
  title: 'Evolved C++',
  description: 'C++ Programming Course for VIVES University of Applied Sciences (Bachelor Degree)',
  themeConfig: {
    nav: [
      {text: 'Toledo', link: 'https://toledo.kuleuven.be/portal'},
      {text: 'DevBit Courses', link: 'https://www.devbit.courses/'},
      {text: 'Report Issue', link: 'https://github.com/BioBoost/course-object-oriented-programming-with-cpp/issues'},
      {text: 'Challenges', link: 'https://github.com/BioBoost/challenges-cpp'}
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
        title: 'Introductory',   // required
        // path: '/foo/',      // optional, which should be a absolute path.
        collapsable: false, // optional, defaults to true
        sidebarDepth: 1,    // optional, defaults to 1
        children: [
          '01-what-is-cpp/',
          '02-hello-world/',
        ]
      },
      {
        title: 'Fundamentals',   // required
        // path: '/foo/',      // optional, which should be a absolute path.
        collapsable: false, // optional, defaults to true
        sidebarDepth: 1,    // optional, defaults to 1
        children: [
          '03-variables-and-datatypes/',
          '04-operators/',
          '05-input-output/',
          '06-branching/',
          '07-loops/',
          '08-arrays/',
          '09-enums/',
          '10-functions/',
        ]
      },
      // {
      //   title: 'Object Oriented Thinking',   // required
      //   path: '/03-object-oriented-thinking/',      // optional, which should be a absolute path.
      //   collapsable: false, // optional, defaults to true
      //   children: [
      //     '/03-object-oriented-thinking/',
      //     '/03-object-oriented-thinking/abstraction/',
      //     '/03-object-oriented-thinking/all_about_objects/',
      //   ]
      // },
      {
        title: 'Object Oriented Programming',   // required
        // path: '/foo/',      // optional, which should be a absolute path.
        collapsable: false, // optional, defaults to true
        sidebarDepth: 1,    // optional, defaults to 1
        children: [
          '11-using-objects/',
          '12-creating-classes/',
          '13-structs/',
          '14-composition/',
          '15-constructors/',
          '16-destructors/',
        ]
      },
      {
        title: 'Compiling and Linking',   // required
        // path: '/foo/',      // optional, which should be a absolute path.
        collapsable: false, // optional, defaults to true
        sidebarDepth: 1,    // optional, defaults to 1
        children: [
          '17-the-compilation-process/',
          '18-makefiles/',
          '19-libraries/'
        ]
      },
      {
        title: 'More Advanced C++',   // required
        // path: '/foo/',      // optional, which should be a absolute path.
        collapsable: false, // optional, defaults to true
        sidebarDepth: 1,    // optional, defaults to 1
        children: [
          '20-pointers/',
          '21-exceptions/'
        ]
      },


      




      // {
      //   title: 'Compilation',   // required
      //   // path: '/foo/',      // optional, which should be a absolute path.
      //   collapsable: false, // optional, defaults to true
      //   sidebarDepth: 1,    // optional, defaults to 1
      //   children: [
      //     '06-the-compilation-process/',
      //   ]
      // },
      // {
      //   title: 'Memory',   // required
      //   // path: '/foo/',      // optional, which should be a absolute path.
      //   collapsable: false, // optional, defaults to true
      //   sidebarDepth: 1,    // optional, defaults to 1
      //   children: [
      //     '07-pointers/',
      //     '08-dynamic-memory-allocation/',
      //   ]
      // },
      // {
      //   title: 'Working with Files',   // required
      //   // path: '/foo/',      // optional, which should be a absolute path.
      //   collapsable: false, // optional, defaults to true
      //   sidebarDepth: 1,    // optional, defaults to 1
      //   children: [
      //     '09-file-streams/',
      //   ]
      // },
      // {
      //   title: 'Guides',
      //   collapsable: false, // optional, defaults to true
      //   sidebarDepth: 1,    // optional, defaults to 1
      //   children: [
      //     ['/guide-linked-lists/', 'Linked List'],
      //   ]
      // },
    ],
    sidebarDepth: 1,
    repo: 'BioBoost/course-object-oriented-programming-with-cpp',
    docsDir: 'docs',
    docsBranch: 'master',
    lastUpdated: 'Last Updated', // string | boolean
    smoothScroll: true
  },
  markdown: {
    lineNumbers: true,
  },
  serviceWorker: true,
  plugins: [
    ['vuepress-plugin-zooming', {
      // selector for images that you want to be zoomable
      selector: 'img',      // default: '.content img'
      options: {
        bgColor: 'black',
        zIndex: 10000,
      },
    }],
    ['container', {
      type: 'output',
      defaultTitle: 'Output',
    }],
    ['container', {
      type: 'definition',
      defaultTitle: 'Definition',
    }],
    ['container', {
      type: 'kata',
      defaultTitle: 'Code Kata',
    }],
  ],
}