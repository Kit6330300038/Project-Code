<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

return new class extends Migration
{
    /**
     * Run the migrations.
     */
    public function up(): void
    {
        Schema::create('reserve_batteries', function (Blueprint $table) {
            $table->id()->unique();
            $table->integer('id_user');
            $table->integer('id_battery');
            $table->integer('id_cabinet');
            $table->dateTime('reserve_time');
            $table->dateTime('out_time');
            $table->integer('status');
        });
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        Schema::dropIfExists('reserve_batteries');
    }
};
