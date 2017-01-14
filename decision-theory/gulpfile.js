var gulp = require('gulp');
var watch = require('gulp-watch');
var less = require('gulp-less');

gulp.task('less', function () {
    gulp.src('./src/less/main.less')
        .pipe(less())
        .pipe(gulp.dest('./src/stylesheets'))
});

gulp.task('watch', function () {
    gulp.watch('./src/less/**/*.less', ['less']);
});