<template>
  <!-- Credits go to https://github.com/sillevl -->
  <div class="iframe-container">
    <iframe
      :src="youtubeUrl"
      frameborder="0"
      allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture"
      allowfullscreen
    >
    </iframe>
  </div>
</template>

<script>
export default {
  props: ["videoId"],
  computed: {
    youtubeUrl: function () {
      return `https://www.youtube.com/embed/${this.videoId}`;
    },
  },
};
</script>

<style>
.iframe-container {
  overflow: hidden;
  /* 16:9 aspect ratio */
  padding-top: 56.25%;
  position: relative;
}

.iframe-container iframe {
   border: 0;
   height: 100%;
   left: 0;
   position: absolute;
   top: 0;
   width: 100%;
}
</style>