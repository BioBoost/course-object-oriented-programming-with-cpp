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
        collapsable: false, // optional, defaults to true
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
          '/a-introductory/01-what-is-cpp/',
          '/a-introductory/02-hello-world/',
        ]
      },
      {
        title: 'Fundamentals',   // required
        // path: '/foo/',      // optional, which should be a absolute path.
        collapsable: false, // optional, defaults to true
        sidebarDepth: 1,    // optional, defaults to 1
        children: [
          '/b-fundamentals/01-variables-and-datatypes/',
          '/b-fundamentals/02-operators/',
          '/b-fundamentals/03-input-output/',
          '/b-fundamentals/04-branching/',
          '/b-fundamentals/05-loops/',
          '/b-fundamentals/06-arrays/',
          '/b-fundamentals/07-enums/',
          '/b-fundamentals/08-functions/',
        ]
      },
      {
        title: 'Object Oriented Thinking',   // required
        // path: '/foo/',      // optional, which should be a absolute path.
        collapsable: false, // optional, defaults to true
        sidebarDepth: 1,    // optional, defaults to 1
        children: [
          '/c-object-oriented-thinking/',
          '/c-object-oriented-thinking/abstraction/',
          '/c-object-oriented-thinking/all_about_objects/',
        ]
      },
      {
        title: 'Object Oriented Programming',   // required
        // path: '/foo/',      // optional, which should be a absolute path.
        collapsable: false, // optional, defaults to true
        sidebarDepth: 1,    // optional, defaults to 1
        children: [
          '/d-object-oriented-programming/01-using-objects/',
          '/d-object-oriented-programming/02-creating-classes/',
          '/d-object-oriented-programming/03-structs/',
          '/d-object-oriented-programming/04-composition/',
          '/d-object-oriented-programming/05-constructors/',
          '/d-object-oriented-programming/06-destructors/',
        ]
      },
      {
        title: 'Compiling and Linking',   // required
        // path: '/foo/',      // optional, which should be a absolute path.
        collapsable: false, // optional, defaults to true
        sidebarDepth: 1,    // optional, defaults to 1
        children: [
          '/e-compiling-and-linking/01-the-compilation-process/',
          '/e-compiling-and-linking/02-makefiles/',
          '/e-compiling-and-linking/03-libraries/'
        ]
      },
      {
        title: 'More Advanced C++',   // required
        // path: '/foo/',      // optional, which should be a absolute path.
        collapsable: false, // optional, defaults to true
        sidebarDepth: 1,    // optional, defaults to 1
        children: [
          '/f-more-advanced-cpp/01-pointers/',
          '/f-more-advanced-cpp/02-exceptions/',
          '/f-more-advanced-cpp/03-file-streams/',
          '/f-more-advanced-cpp/04-dynamic-memory-allocation/',
          '/f-more-advanced-cpp/05-standard-templating-libraries/'
        ]
      },
      {
        title: 'Inheritance',   // required
        // path: '/foo/',      // optional, which should be a absolute path.
        collapsable: false, // optional, defaults to true
        sidebarDepth: 1,    // optional, defaults to 1
        children: [
          '/g-inheritance/01-basic-inheritance/',
          '/g-inheritance/02-interfaces/',
          '/g-inheritance/03-polymorphism/',
          '/g-inheritance/04-multiple-inheritance/'
        ]
      },
      {
        title: 'Mental Topics',   // required
        // path: '/foo/',      // optional, which should be a absolute path.
        collapsable: false, // optional, defaults to true
        sidebarDepth: 1,    // optional, defaults to 1
        children: [
          '/h-mental-topics/01-threads/',
          '/h-mental-topics/02-operator-overloading/',
          '/h-mental-topics/03-templating/'
        ]
      },
      {
        title: 'Guides',
        // path: '/foo/',      // optional, which should be a absolute path.
        collapsable: false, // optional, defaults to true
        sidebarDepth: 1,    // optional, defaults to 1
        children: [
          ['/x-guides/linked-lists/', 'Linked Lists'],
          ['/x-guides/json/', 'JSON'],
        ]
      },
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